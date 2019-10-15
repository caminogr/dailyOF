#include "ofApp.h"

int iterateCount = 1000;
int meshZ = 3000;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
//    meshZ += ofRandom(-30,70);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    ofSetColor(255);

    vboMesh.clear();
    
    for (int i=0; i<iterateCount; i++) {
        vboMesh.addVertex(ofVec3f(i, i, 0));
        vboMesh.addVertex(ofVec3f(0, 0, meshZ * i/2));
        vboMesh.addVertex(ofVec3f(1, 1, meshZ * i));
    }
    
    ofPushMatrix();
    ofRotateDeg(430, 10, 10, 10);
//    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    glPointSize(1.0);
    vboMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
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
