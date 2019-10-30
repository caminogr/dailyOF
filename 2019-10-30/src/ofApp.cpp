#include "ofApp.h"
float tnoise = 0.0;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    shader.load("shader.vert","shader.frag");

    float planeScale = 5.0;

    int planeWidth = ofGetWidth() * planeScale;
    int planeHeight = ofGetHeight() * planeScale;
    int planeGridSize = 60;
    int planeColums = planeWidth / planeGridSize;
    int planeRows = planeHeight / planeGridSize;

    plane.set(planeWidth, planeHeight, planeColums, planeRows, OF_PRIMITIVE_TRIANGLES);
}

//--------------------------------------------------------------
void ofApp::update(){
    float columnNoise = ofMap(ofNoise(tnoise), 0,1,0,100);
    float rowNoise = ofMap(ofNoise(tnoise), 0,1,0,100);
    tnoise += 0.003;
    plane.setResolution(columnNoise, rowNoise);
}

//--------------------------------------------------------------
void ofApp::draw(){
    shader.begin();
    shader.setUniform1f("time", ofGetElapsedTimef());
    
    plane.drawWireframe();
    shader.end();
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
