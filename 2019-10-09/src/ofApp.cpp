#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    int steps = 1440;
    float radiusSeed = 10000;
    float stepSize = (M_PI * 2) / steps;
    for(float i = 0; i < (M_PI * 2); i += stepSize) {
        // not working
        radius += radius + (ofNoise(abs(sin(i)) * radiusSeed));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    radius = 200.0;
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    ofSetColor(255);
    ofDrawCircle(1, 1, radius);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
