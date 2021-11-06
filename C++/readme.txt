"C_Cpp.clang_format_style": "{ BasedOnStyle: Chromium, IndentWidth: 4}", //大括號不換行！
這行可以加到setting.json 裏面

如果遇到 xcrun: error: invalid active developer path (/Library/Developer/CommandLineTools), missing xcrun at: /Library/Developer/CommandLineTools/usr/bin/xcrun
終端機執行這段就可以了 "xcode-select --install"

環境安裝：
終端機安裝pyenv之後，要找出以下檔案然後輸入那些指令儲存
然後pyenv global 3.9.4（後面的數字是版本號碼，看是安裝哪一種的）

.bash
"
export PATH="$HOME/.pyenv/bin:$PATH"
eval "$(pyenv init -)"
eval "$(pyenv virtualenv-init -)"
"

.zprofile
"
# Setting PATH for Python 3.9
# The original version is saved in .zprofile.pysave
PATH="/Library/Frameworks/Python.framework/Versions/3.9/bin:${PATH}"
export PATH
eval "$(/opt/homebrew/bin/brew shellenv)"
"

.zsh
"
echo 'eval "$(pyenv init --path)"' >> ~/.zprofile
"

.zshrc
"
export PYENV_ROOT="$HOME/.pyenv"
export PATH="$PYENV_ROOT/bin:$PATH"
eval "$(pyenv init --path)"
eval "$(pyenv init -)"
"