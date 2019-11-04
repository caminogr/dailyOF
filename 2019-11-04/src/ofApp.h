#pragma once

#include "ofMain.h"
#include "ofxCv.h"
//#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    ofVideoGrabber camera;
    ofxCv::ContourFinder contourFinder;
    ofxCv::RunningBackground background;
    ofImage thresholded;
    ofPixels pixels;
};

