THEME_COLOR = "#375362"

from tkinter import *
from quiz_brain import QuizBrain

class QuizInterface():
    def __init__(self, quiz_brain: QuizBrain):
        self.quiz = quiz_brain

        self.window = Tk()
        self.window.config(padx = 20, pady = 20, background=THEME_COLOR)
        self.window.title('Quizzler')


        self.score = Label(text = 'Score: 0', fg='white', background=THEME_COLOR)
        self.score.grid(row=0, column = 1)

        self.canvas = Canvas(width = 300, height = 250, bg='white')
        self.question_text = self.canvas.create_text(
            150,
            125,
            width=280,
            text="Some filler text",
            fill=THEME_COLOR,
            font=('Arial', 20, 'italic')
        )
        self.canvas.grid(row = 1, column = 0, columnspan = 2, pady = 50)

        true_img = PhotoImage(file = 'images/true.png')
        false_img = PhotoImage(file='images/false.png')
        self.accept_button = Button(image = true_img, highlightthickness=0, command=self.check_true)
        self.accept_button.grid(row = 2, column = 0)
        self.decline_button = Button(image = false_img, highlightthickness=0, command=self.check_false)
        self.decline_button.grid(row=2, column=1)

        self.get_next_question()

        self.window.mainloop()

    def get_next_question(self):
        self.canvas.config(bg='white')
        if self.quiz.still_has_questions():
            self.score.config(text=f'Score: {self.quiz.score}')
            q_text = self.quiz.next_question()
            self.canvas.itemconfig(self.question_text, text=q_text)
        else:
            self.canvas.itemconfig(self.question_text, text='You have reached the end of the quiz!')
            self.accept_button.config(state='disabled')
            self.decline_button.config(state='disabled')


    def check_true(self):
        self.give_feedback(self.quiz.check_answer('True'))


    def check_false(self):
        self.give_feedback(self.quiz.check_answer('False'))


    def give_feedback(self, bool):
        if bool:
            self.canvas.config(bg='green')
        else:
            self.canvas.config(bg='red')
        self.window.after(1000, self.get_next_question)



