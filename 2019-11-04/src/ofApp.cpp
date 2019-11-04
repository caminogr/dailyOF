#include "ofApp.h"
#include <glm/glm.hpp>


//--------------------------------------------------------------
void ofApp::setup(){
    camera.initGrabber(1280, 720);
    background.setThresholdValue(90);
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
    background.update(camera, thresholded);
    thresholded.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    pixels = thresholded.getPixels();
    for (int y=0; y<pixels.getHeight(); y+=10) {
             for (int x=0; x<pixels.getWidth(); x+=10) {

                 ofColor color = pixels.getColor(x, y);
                 ofSetColor(color);
                 float time = ofGetElapsedTimef();
                 int z = ofRandom(0,50);
                 float motion_z = glm::abs(glm::exp(sin(time)) * glm::mod(z,9))+ 1;
                 ofDrawCircle(x, y, motion_z);
             }
         }
}
