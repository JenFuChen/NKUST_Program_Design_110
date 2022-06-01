from tkinter import *
from random import randint
from threading import Timer
from tkmacosx import Button
window = Tk()
window.title("打磚塊遊戲")
game_Y_size = 10
game_X_size = 10
english_list = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
pick = []
shout_score = 0
get_score = StringVar()
get_score.set('score='+str(shout_score))
t = None
counter = 1
state = []
counter_XX = 0


def change_time():
    global t, btn, counter, state, a, counter_XX
    set_x = randint(0, 9)
    buffer_x = randint(0, 9)
    buffer = []
    if (a == 1):
        buffer = []
        for y in range(game_Y_size):
            buffer.append([])
            for x in range(game_X_size):
                buffer[y].append('')
        for y in range(1, game_Y_size):
            for x in range(game_X_size):
                buffer[y][x] = state[y - 1][x]
        for y in range(game_Y_size):
            for x in range(game_X_size):
                btn[y][x].configure(text=buffer[y][x])
    # state[0][set_x] = 'X'
    for y in range(game_Y_size):
        buffer.append([])
        for x in range(game_X_size):
            buffer[y].append('')
    for y in range(1, game_Y_size):
        for x in range(game_X_size):
            buffer[y][x] = state[y-1][x]
    buffer[0][buffer_x] = 'x'
    del state[:]
    for y in range(0, game_Y_size):
        state.append([])
        for x in range(game_X_size):
            state[y].append('')
            state[y][x] = buffer[y][x]
    for y in range(game_Y_size):
        for x in range(game_X_size):
            btn[y][x].configure(text=buffer[y][x])
    # print('===================================')
    # for y in range(game_Y_size):
    #     print(state[y])

    for x in range(game_X_size):
        if(state[game_Y_size-1][x] == 'x'):
            counter_XX += 1
    if(counter_XX == 10):
        english.place_forget()
        del pick[:]
        pick.append("gameover")
        english_place()
        pause()
        return
    t = Timer(1, change_time)
    t.start()


def pause():
    global root
    global t
    t.cancel()


def random_english():
    global english
    a = randint(1, 5)
    for i in range(a):
        pick.append(english_list[randint(0, 25)])


random_english()
btn = []


def button_set():
    global bnt, state
    for y in range(game_Y_size):
        btn.append([])
        state.append([])
        for x in range(game_X_size):
            state[y].append('')
            btn[y].append(Label(window, width=4, height=2,
                          relief=RAISED, anchor='center'))
            btn[y][x].config(text=' ', font='30', bg='#ffffff')
            btn[y][x].place(x=50+x*50, y=30+y*45)


button_set()
a = 0


def play(event):
    global state, btn, english, pick, shout_score, a
    StrA = "".join(pick)
    if(StrA == myentry.get()):
        a = 0
        for y in range(game_Y_size-1, -1, -1):
            for x in range(game_X_size):
                if(state[y][x] == 'x'):
                    state[y][x] = ''
                    a = 1
                    t = Timer(0.1, change_time)
                    break
            if(a == 1):
                break
        shout_score += 1
        get_score.set('score=' + str(shout_score))
        del pick[:]
        english.place_forget()
        random_english()
        english_place()
        myentry.delete(0, END)
    else:
        print('no')
        myentry.delete(0, END)


t = Timer(1, change_time)
t.start()
myentry = Entry(window, textvariable=input, font=('arial', 20))
myentry.bind("<Return>", play)
myentry.place(x=200, y=500, width=200, height=40)
myentry.focus()


def english_place():
    global english
    english = Label(window, text=pick, font=(
        'arial', 15), fg='black')
    english.place(x=50, y=500, height=30)


english_place()
score = Label(window, textvariable=get_score, font=(
    'arial', 15), bg="skyblue", fg='red')
score.place(x=430, y=500, height=30)
window.mainloop()
