cd Srceng-mod-launcher
git clone https://gitlab.com/LostGamer/android-sdk
export ANDROID_SDK_HOME=$PWD/android-sdk
git pull
./build-vpk.sh
./waf configure -T release &&
./waf build
