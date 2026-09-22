"""Smoke-check coursework executables and the text adventure without editing fixtures."""
from pathlib import Path
import subprocess
import sys
import tempfile

root = Path(__file__).resolve().parents[1]
build = Path(sys.argv[1]).resolve()
suffix = '.exe' if sys.platform == 'win32' else ''

def run(name, inputs, cwd=None):
    result = subprocess.run([str(build / (name + suffix))], input=inputs, text=True,
                            capture_output=True, cwd=cwd or root, timeout=10)
    assert result.returncode == 0, result.stderr
    return result.stdout

assert '8 + 2 = 10' in run('calculator', '8 + 2\nn\n')
assert 'Cannot divide by zero' in run('calculator', '8 / 0\n8 / 2\nn\n')
assert 'Invalid expression' in run('calculator', 'oops\n8 + 2\nn\n')
clock = run('chada-clocks', '23\n59\n59\n3\n4\n')
assert '00:00:00' in clock and '12:00:00 AM' in clock
bank = run('investment-calculator', '\n1000\n100\n5\n1\nn\n')
assert '1,051.16' in bank or '1051.16' in bank, bank
with tempfile.TemporaryDirectory() as directory:
    p = Path(directory)
    (p / 'FahrenheitTemperature.txt').write_text('Freezing 32\nBoiling 212\n')
    run('temperature-converter', '', p)
    assert (p / 'CelsiusTemperature.txt').read_text().splitlines() == ['Freezing 0.00','Boiling 100.00']
game = subprocess.run([sys.executable, str(root / 'python/fundamentals/TextBasedGame.py')],
                      input='exit\n', text=True, capture_output=True, timeout=5)
assert game.returncode == 0, game.stderr
assert 'Collect 6 items' in game.stdout
age = subprocess.run([sys.executable, str(root / 'python/fundamentals/NameAge.py')],
                     input='Alex\n1.5\n-1\n30\n', text=True, capture_output=True, timeout=5)
assert age.returncode == 0 and 'Hello Alex!' in age.stdout
print('PASS: calculator validation, midnight rollover, annual interest example, temperatures, game exit, age validation')
