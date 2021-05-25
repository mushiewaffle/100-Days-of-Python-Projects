
with open("my_file.txt", mode='a') as file:
    contents = file.write("new text.")
    print(contents)

with open("new_file.txt", mode='w') as file:
    contents = file.write("new text.")
    print(contents)