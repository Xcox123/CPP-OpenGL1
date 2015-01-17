git status
git add .
git status
set /p commitComment=Enter the Commit Comment:%=%
git commit -m "%commitComment%"
git status
git pull origin master
git push origin master