from tkinter import *
import pandas
import random

BACKGROUND_COLOR = "#B1DDC6"
current_card = {}

try:
    data = pandas.read_csv('data/words_to_learn.csv')
except FileNotFoundError:
    original_data = pandas.read_csv('data/french_words.csv')
    to_learn = original_data.to_dict(orient='records')
else:
    to_learn = data.to_dict(orient='records')

def next_card():
    global current_card, flip_timer
    window.after_cancel(flip_timer)

    current_card = random.choice(to_learn)
    french = current_card['French']
    canvas.itemconfig(card_title, text='French', fill='black')
    canvas.itemconfig(card_body, text=french, fill='black')
    canvas.itemconfig(card_background, image=front_image)
    flip_timer = window.after(3000, flip)

def is_known():
    to_learn.remove(current_card)
    data = pandas.DataFrame(to_learn)
    data.to_csv('data/words_to_learn.csv', index=False)
    next_card()

def flip():
    english = current_card['English']
    canvas.itemconfig(card_title, text='English', fill='white')
    canvas.itemconfig(card_body, text=english, fill='white')
    canvas.itemconfig(card_background, image=back_image)

window = Tk()
window.config(padx = 50, pady = 50, background = BACKGROUND_COLOR)
window.title("Flashy")
flip_timer = window.after(3000, flip)

canvas = Canvas(height=526, width=800)
front_image = PhotoImage(file="images/card_front.png")
back_image = PhotoImage(file="images/card_back.png")
card_background = canvas.create_image(400, 263, image=front_image)
canvas.config(bg = BACKGROUND_COLOR, highlightthickness=0)
card_title = canvas.create_text(400, 150, text="", font=('Ariel', 40, 'italic'))
card_body = canvas.create_text(400, 263, text="", font=('Ariel', 60, 'bold'))
canvas.grid(row=0, column = 0, columnspan=2)

wrong_image = PhotoImage(file="images/wrong.png")
wrong_button = Button(image=wrong_image, highlightthickness=0, command = next_card)
wrong_button.grid(row = 1, column = 0)

right_image = PhotoImage(file="images/right.png")
right_button = Button(image=right_image, highlightthickness=0, command = is_known)
right_button.grid(row = 1, column = 1)

next_card()

window.mainloop()