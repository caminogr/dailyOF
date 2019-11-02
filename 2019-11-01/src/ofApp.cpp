#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    shader.load("shader.vert","shader.frag");
    foregroundImage.load("A.jpg");
    // foregroundImage.allocate(1280, 720, OF_IMAGE_COLOR);


    camera.initGrabber(1280, 720);
    thresholded.allocate(1280, 720, OF_IMAGE_COLOR);
    // contourFinder.setMinAreaRadius(10);
    // contourFinder.setMaxAreaRadius(200);
    background.setLearningTime(900);
    background.setThresholdValue(80);

    resetBackgroundButton.addListener(this, &ofApp::resetBackgroundPressed);
    gui.setup();
    gui.add(bgThresh.setup("cbackground thresh", 50, 0, 100));
    gui.add(contourThresh.setup("cocntour finder thresh", 127, 0, 255));
    gui.add(resetBackgroundButton.setup("reset bacckground"));
}

//--------------------------------------------------------------
void ofApp::update(){
     camera.update();
    // if(camera.isFrameNew()) {
      // background.setThresholdValue(80);
      // // background.setThresholdValue(bgThresh);
      background.update(camera, thresholded);
      thresholded.update();

      // contourFinder.setThreshold(contourThresh);
      // contourFinder.findContours(thresholded);
    // }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    // thresholded.draw(10,10);
    ofSetColor(255, 0, 0);

    // contourFinder.draw();
    // GUI
    gui.draw();

    // camera.draw(20,20);




    shader.begin();
    // here is where the fbo is passed to the shader
    // shader.setUniformTexture("thresholded", thresholded.getTexture(), 1 );
    // shader.setUniformTexture("foregroundTex", foregroundImage.getTexture(), 1 );
    // foregroundImage.draw(0, 0);
     shader.setUniform1f("time", ofGetElapsedTimef());
    shader.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
     thresholded.draw(10,10);
    
    shader.end();
}

void ofApp::resetBackgroundPressed() {
  background.reset();
}

