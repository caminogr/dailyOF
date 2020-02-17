#include "ofApp.h"

int cubeCount = 800;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    camera.setPosition(ofVec3f(ofGetWidth()/2,ofGetHeight()/2,400));
    ofEnableDepthTest();
    ofEnableSmoothing();

    light.enable();
    light.setDirectional();
    //環境反射光
    light.setAmbientColor(ofFloatColor(0.7,0.7,0.7,1.0));
    //拡散反射光
    light.setDiffuseColor(ofFloatColor(1.0,1.0,1.0));
    //鏡面反射光
    light.setSpecularColor(ofFloatColor(1.0,1.0,1.0));
    
    // blur
    ofSetLogLevel(OF_LOG_VERBOSE);
    blur.setup(ofGetWidth(), ofGetHeight(), 62, 1, 1, 30);
    blur.setScale(0.1);

    for(int i=0; i<cubeCount; i++) {
        box.set(ofRandom(0,40), ofRandom(0,40), ofRandom(0,40));
        box.setPosition(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()), ofRandom(-1000,0));
        boxes.push_back(box);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    blur.begin();
    camera.begin();
    for (int i=0; i<boxes.size(); i++) {
        boxes[i].draw();
    }
    camera.end();
    blur.end();
    blur.draw();
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







