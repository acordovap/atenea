INSTALL GUIDE
=============

Software Requirements
---------------------

 * g++
 * QT >= 4.3 with opengl and networking support
 * cmake
 * Eigen2
 * Google protocol buffers (protoc)
 * OpenGL
 * GLU
 * libjpeg
 * libpng

To get all of these packages in (k)ubuntu, run:
sudo apt-get install g++ libqt4-dev libeigen2-dev protobuf-compiler libprotobuf-dev cmake

To get all of these packages in Fedora, run:
sudo yum install subversion cmake qt qt-devel gcc gcc-c++ protobuf-compiler protobuf-c-devel protobuf-devel libdc1394-devel libjpeg-turbo-devel libpng-devel

Compilation
-----------

Build de code by running:

mkdir build
cd build
cmake ..
make

The project *should* build without errors or warnings.




