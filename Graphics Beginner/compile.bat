@echo off
setlocal

:: Path to glslc
set GLSLC="C:\VulkanSDK\1.3.296.0\Bin\glslc.exe"

:: Directory containing shaders
set SHADER_DIR=shaders

:: Check if the shader directory exists
if not exist "%SHADER_DIR%" (
    echo Shader directory not found: %SHADER_DIR%
    pause
    exit /b
)

:: Compile vertex shaders
for %%f in (%SHADER_DIR%\*.vert) do (
    echo Compiling: %%f
    %GLSLC% -c %%f -o "%SHADER_DIR%\%%~nf.vert.spv"
)

:: Compile fragment shaders
echo Compiling fragment shaders...
for %%f in (%SHADER_DIR%\*.frag) do (
    echo Compiling: %%f
    %GLSLC% -c %%f -o "%SHADER_DIR%\%%~nf.frag.spv"
)

echo Shader compilation complete.
pause
