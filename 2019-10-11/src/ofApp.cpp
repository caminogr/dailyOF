#include "ofApp.h"
float xNoise;
float yNoise;
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetCurveResolution(25);

}

//--------------------------------------------------------------
void ofApp::update(){
    xNoise += 0.1;
    yNoise += 0.1;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    int y = ofGetHeight()/2;
    int x = ofGetWidth()/2;
    
    ofNoFill();
    ofSetColor(255);
    
    for(int i = 0; i < 100000; i++){
        if (i < 10) {
            continue;
        }
    
        ofRotateDeg(15);
        ofDrawBezier(x,y,
                 -2 * x * i,y * i,
                 x * i,-2 * y * i,
                 x,y);
    }
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
