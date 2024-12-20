@echo off
setlocal

REM Параметр для указания пути к репозиторию
set REPO_DIR=

REM Переход в директорию репозитория
cd /d "%REPO_DIR%"
if errorlevel 1 (
    echo Failed to navigate to repository directory.
    exit /b 1
)

REM Обновление репозитория
git checkout main
git pull origin main

REM Обход всех подкаталогов для поиска файлов проекта
for /r %%D in (.) do (
    if exist "%%Dtests.c" (
        echo Found solution file: %%D*.sln
        echo Building solution: %%D*.sln...
        msbuild "%%Dtests.c" /p:Configuration=Release
        if errorlevel 1 (
            echo Failed to build project in %%D
            exit /b 1
        )
    ) else (
        echo No solution files found in %%D
    )
)

echo Build completed successfully.
endlocal
exit /b 0