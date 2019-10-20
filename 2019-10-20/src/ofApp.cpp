#include "ofApp.h"

int cubeCount = 800;
float x;
float y;
float z;
float tx;
float ty;
float tz;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    camera.setPosition(ofVec3f(ofGetWidth()/2,ofGetHeight()/2,700));
    ofEnableDepthTest();
    ofEnableSmoothing();
    light.enable();
    light.setSpotlight();
    
    //環境反射光
    light.setAmbientColor(ofFloatColor(1,0.2,0.2,1.0));
    //拡散反射光
    light.setDiffuseColor(ofFloatColor(1.0,1.0,1.0));
    //鏡面反射光
    light.setSpecularColor(ofFloatColor(1.0,1.0,1.0));

    for(int i=0; i<cubeCount; i++) {
        box.set(ofRandom(0,40), ofRandom(0,40), ofRandom(0,40));
        box.setPosition(ofRandom(0,ofGetWidth()), ofRandom(0,ofGetHeight()), ofRandom(-1000,0));
        boxes.push_back(box);
    }
    
    tx = ofGetWidth()/2;
    ty = ofGetHeight()/2;
    tz = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    x = ofMap(ofNoise(tx), 0, 1, 0, ofGetWidth());
    y = ofMap(ofNoise(ty), 0, 1, 0, ofGetHeight());
    z = ofMap(ofNoise(tz), 0, 1, -400, 0);

    light.setPosition(x, y, z);
    tx += 0.01;
    ty += 0.01;
    tz += 0.2;
}

//--------------------------------------------------------------
void ofApp::draw(){
    camera.begin();
    for (int i=0; i<boxes.size(); i++) {
        boxes[i].draw();
    }

    camera.end();
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
