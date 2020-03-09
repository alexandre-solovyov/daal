
set PATH=C:\msys64\usr\bin;%PATH%

rem in the msys shell:
rem Update the package database and core system packages with:
rem pacman -Syu
rem change in the /etc/pacman.conf:
rem SigLevel = Never
rem #SigLevel    = Required DatabaseOptional
rem install make: pacman -S msys/make

call "C:\Program Files (x86)\Microsoft Visual Studio\2017\WDExpress\VC\Auxiliary\Build\vcvarsx86_amd64.bat"
rem set PATH=C:\Program Files (x86)\Microsoft Visual Studio\2017\WDExpress\VC\Tools\MSVC\14.10.25017\bin\Hostx64\x64;%PATH%

rem Install MKL from remote package
rem call .\scripts\mklfpk.bat

rem call "C:\Program Files (x86)\IntelSWTools\compilers_and_libraries\windows\tbb\bin\tbbvars.bat" intel64
call "C:\Program Files (x86)\IntelSWTools\compilers_and_libraries\windows\bin\compilervars.bat" intel64
call "C:\tbb\bin\tbbvars.bat" intel64

rem make -f makefile daal PLAT=win32e COMPILER=vc
rem make -f makefile daal PLAT=win32e CORE.ALGORITHMS.CUSTOM="kmeans" REQCPU="" -j16

make -f makefile daal PLAT=win32e COMPILER=vc CORE.ALGORITHMS.CUSTOM="naivebayes" REQCPU="" -j16
