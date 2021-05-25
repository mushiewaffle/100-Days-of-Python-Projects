import smtplib

#Jan, 1, 1990
PASS = "d6f%jzaK#ab7f@Tg"

my_email = "kevin.wu1998testemail@gmail.com"

connection = smtplib.SMTP("smtp.gmail.com")

connection.starttls() #makes connection secure/encrypted

connection.login(user = my_email, password = PASS)

connection.sendmail(from_addr=my_email, to_addrs="kwu022@ucr.edu", msg = "Hello World!")
connection.close()

