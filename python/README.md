# Python fundamentals

Requires Python 3. Run scripts from `fundamentals/`, for example:

```bash
cd fundamentals
python TextBasedGame.py
```

**Exposé** is a fictional text adventure: move through rooms, collect six items, and avoid the end room until ready. Use `go north`, `go south`, `go east`, `go west`, `get item name`, or `exit`.

The remaining scripts are individual exercises in formatting names, ages, seasons, guessing games, change calculation, and file I/O. Run them individually and follow their input prompts. `Test.txt` accompanies the file exercise.

These are preserved learning exercises. `FileIO.py` now resolves its fixture beside the script instead of using a personal absolute path; running it appends a line to `Test.txt`. `NameAge.py` rejects malformed ages and uses a fictional example; its birth year is an age-based estimate. Syntax validation is separate from interactive behavior verification; see the repository verification notes.
