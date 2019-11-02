#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    void resetBackgroundPressed();

    ofVideoGrabber camera;
    ofxCv::ContourFinder contourFinder;
    ofxCv::RunningBackground background;
    ofImage thresholded;
    ofImage foregroundImage;
    // ofFbo maskFbo;

    ofShader shader;

    ofxPanel gui;
    ofxFloatSlider bgThresh;
    ofxFloatSlider contourThresh;
    ofxButton resetBackgroundButton;
};
