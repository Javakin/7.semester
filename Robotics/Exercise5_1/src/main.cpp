#include <iostream>
#include <rw/math.hpp> // Pi, Deg2Rad
#include <rw/math/Q.hpp>
#include <rw/math/Transform3D.hpp>
#include <rw/math/RPY.hpp>
#include <rw/math/Vector3D.hpp>
#include <rw/math/EAA.hpp>


using namespace std;
using namespace rw::math;


int main(int argc, char** argv) {

    // define the frames robwork
    //Vector3D<double> hans ( 1,0,0);
    //RPY<double> rot(0.25,0.4,0.1);
    //Transform3D<double> test(hans, rot.toRotation3D());

    //cout << "This is the elements of the transform matrix" <<  test(0,0) << endl;

    // verify that

    // ii)  compute the linear segments

    // iii) compute the parabolic blen

    cout << "RobWork is ready to run" << endl;


    return 0;
}

