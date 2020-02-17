#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetColor(255);
   
    for (int i=0; i<1000; i++) {
        randomX = ofRandom(-100, 100);
        randomY = ofRandom(-100, 100);
        randomZ = ofRandom(-100, 100);

        vboMesh.addVertex(ofVec3f(randomX, randomY, randomZ));
        vboMesh.addVertex(ofVec3f(randomX/2, randomY/2,  randomZ/2));
        vboMesh.addVertex(ofVec3f(randomX * 3, randomY * 3, randomZ * 3));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofPushMatrix();
    ofRotateDeg(315, 10, 10, 10);
    ofScale(1,1,60);
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    glPointSize(1.0);
    vboMesh.setMode(OF_PRIMITIVE_TRIANGLES);
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
