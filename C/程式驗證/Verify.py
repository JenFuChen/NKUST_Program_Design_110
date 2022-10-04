x = 0
cnt = 1
failed = []
error = 0


'''
把這兩行加在主程式最上面，就會自己吃資料然後吐出來
freopen("input.txt", "r", stdin);
freopen("classmates_output.txt", "w", stdout);
'''


class bcolors:
    # https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
    OK = '\033[92m'  # GREEN
    WARNING = '\033[93m'  # YELLOW
    FAIL = '\033[91m'  # RED
    RESET = '\033[0m'  # RESET COLOR


print(end='', file=open("verify_result.txt", "w"))
with open('answer_output.txt', 'r') as answer:
    with open('user_output.txt', 'r') as test:
        for answer, test in zip(answer.readlines(), test.readlines()):
            answer = answer.strip("\n")  # 將換行符號刪除再存回
            test = test.strip("\n")  # 將換行符號刪除再存回
            if (answer != test):  # verify the test output
                text = '【No.' + str(cnt) + '】 FAIL' + '\tYour Output：' + \
                    test + '\tCorrect output：' + answer
                print(text, file=open("verify_result.txt", "a"))
                print(bcolors.FAIL + text + bcolors.RESET)
                failed.append(cnt)
                x = 1
                error += 1
            else:
                text = '【No.' + str(cnt) + '】 PASS'
                print(text, file=open("verify_result.txt", "a"))
                print(bcolors.OK + text + bcolors.RESET)
            cnt += 1
        if (x == 1):
            text = 'The Output Has ' + str(error)+' Problems'

            print(text, file=open("verify_result.txt", "a"))
            print(bcolors.WARNING + text + bcolors.RESET)
            print('Failed In No.' + str(failed),
                  file=open("verify_result.txt", "a"))
            print(bcolors.WARNING + 'Failed In No.' +
                  str(failed) + bcolors.RESET)
        else:
            print(bcolors.OK + '! ALL PASS !' + bcolors.RESET)
            print('! ALL PASS !', file=open("verify_result.txt", "a"))
