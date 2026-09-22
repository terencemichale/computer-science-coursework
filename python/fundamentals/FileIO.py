from pathlib import Path

TEST_FILE = Path(__file__).with_name("Test.txt")
print("Opening file Test.txt. (READ ONLY)")
# f = open("Test.txt")  # create file object
f = TEST_FILE.open("r", encoding="utf-8")

print("Reading file Test.txt.")
contents = f.read()  # read file text into a string

print("Closing file Test.txt.")
f.close()  # close the file

print("\nContents of Test.txt:")
print(contents)

print("\nOpening file Test.txt. (APPEND)")
f = TEST_FILE.open("a", encoding="utf-8")

print("\nWriting file Test.txt.")
f.write("\nAdd more values to Test.txt.")

print("Closing file Test.txt.")
f.close()

print("Opening file Test.txt. (READ ONLY)")
# f = open("Test.txt")  # create file object
f = TEST_FILE.open("r", encoding="utf-8")

print("Reading file Test.txt.")
contents = f.read()  # read file text into a string

print("Closing file Test.txt.")
f.close()  # close the file

print("\nContents of Test.txt:")
print(contents)

#
# def read_file(filename):
#     input_file = open(filename, "r")
#     file_contents = []
#     for line in input_file:
#         file_contents.append(line)
#     close(filename)
#     return file_contents
