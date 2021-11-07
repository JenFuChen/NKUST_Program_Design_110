# README
C/C++ Python all here

---
## MacOS Pyenv環境建置

### 環境安裝：
終端機安裝 **pyenv** 之後，找出以下檔案並輸入指令儲存，全部儲存後重開終端機並執行  ``` 
pyenv global 3.9.4``` 數字是版本號碼

> **.bash**
``` cmd
export PATH="$HOME/.pyenv/bin:$PATH"
eval "$(pyenv init -)"
eval "$(pyenv virtualenv-init -)"
```

> **.zprofile**
``` cmd
# Setting PATH for Python 3.9
# The original version is saved in .zprofile.pysave
PATH="/Library/Frameworks/Python.framework/Versions/3.9/bin:${PATH}"
export PATH
eval "$(/opt/homebrew/bin/brew shellenv)"
```

> **.zsh**
```cmd
echo 'eval "$(pyenv init --path)"' >> ~/.zprofile
```

> **.zshrc**
```cmd
export PYENV_ROOT="$HOME/.pyenv"
export PATH="$PYENV_ROOT/bin:$PATH"
eval "$(pyenv init --path)"
eval "$(pyenv init -)"
```

---
## VsCode 使用教學

### 編輯器設定 Setting.json ：
>**大括號不換行**
```json
"C_Cpp.clang_format_style": "{ BasedOnStyle: Chromium, IndentWidth: 4}"
```

>**更改C++編譯輸出路徑** &emsp;
>更改 **./&nbsp;&nbsp;/** 指定路徑
``` json
"code-runner.executorMap": {
    "cpp": "cd $dir && g++  $fileName -o ./build/$fileNameWithoutExt && ./build/$fileNameWithoutExt"
}
```

>**終端機字體**
```json
"terminal.integrated.fontSize": 14
```

>**編輯器字體**
```json
"editor.fontSize": 18
```

### Error 情況：
>**如果在終端機看到以下這串錯誤**
>**則執行這段```xcode-select --install```**
``` cmd
xcrun: error: invalid active developer path (/Library/Developer/CommandLineTools), missing xcrun at: /Library/Developer/CommandLineTools/usr/bin/xcrun
```

### 搭配 GitHub：

>**提取**

>**推送**

>**同步**

---
>**...建置中**
