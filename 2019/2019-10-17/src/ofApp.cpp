#include "ofApp.h"

float radius = 160;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetColor(255);
    for (int i=0; i<500; i++) {
        float z = ofRandom(-1,1);
        float phi = ofDegToRad(ofRandom(360));
        float x = sqrt(1 - z * z) * cos(phi);
        float y = sqrt(1 - z * z) * sin(phi);
        vboMesh.addVertex(radius * ofVec3f(x, y, z));
        vboMesh.addVertex(1.3*radius * ofVec3f(x*2, y*2, z*2));
        vboMesh.addVertex(1.8*radius * ofVec3f(y*2, z*2, x*2));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    glPointSize(1.0);
    vboMesh.setMode(OF_PRIMITIVE_LINE_LOOP);
    vboMesh.draw();
    ofPopMatrix();
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
