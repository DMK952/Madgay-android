cd Srceng-mod-launcher
git clone https://gitlab.com/LostGamer/android-sdk
export ANDROID_SDK_HOME=$PWD/android-sdk
git pull
./waf configure -T release --javac-source-target=8 &&
./waf build
