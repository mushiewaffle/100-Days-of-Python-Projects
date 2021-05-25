from tkinter import *

window = Tk()

window.title('My First GUI Program')
window.minsize(width = 500, height = 300)
window.config(padx = 20, pady = 20)

#Label
my_label = Label(text="I am a Label", font = ('Arial', 24, 'bold'))
my_label.grid(row=0, column=0)
my_label.config(padx = 50, pady = 20)

def button_clicked():
    # my_label['text'] = 'Button got clicked!'
    my_label.config(text = input.get())

button = Button(text = 'Click me', command = button_clicked)
button.grid(row=1, column=1)

#Entry

input = Entry(width = 10)
input.grid(row=2, column=3)

new_button = Button(text = 'Click me')
new_button.grid(row=0, column=2)

window.mainloop()
