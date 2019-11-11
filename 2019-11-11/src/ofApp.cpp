#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
     time = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    cam.begin();
    
    sphere.setPosition(ofVec3f(0, 0, 0));
    sphere.set(150, 20);
    sphere.setResolution(40);

    vboMesh = sphere.getMesh();
    vector<ofVec3f> vertices;
    vector<ofVec3f> sub_vertices;
    
    for(int i=0; i<vboMesh.getVertices().size(); i++){
        int noiseA = ofMap(ofNoise(time), 0,1,0,29);
        int noiseB = ofMap(ofNoise(time), 0,1,0,13);
        if (i%noiseA == 0) {
            vertices.push_back(vboMesh.getVertices()[i]);
        }
        if (i%noiseB == 0) {
            sub_vertices.push_back(vboMesh.getVertices()[i]);
        }
    }

    ofSetPolyMode(OF_POLY_WINDING_ODD);;
    ofNoFill();
    ofSetColor(255);

    ofBeginShape();
    ofVertices(vertices);
    ofEndShape(true);
    
    
    ofNoFill();
    ofSetColor(255, 0,0);

    ofBeginShape();
    ofVertices(sub_vertices);
    ofEndShape(true);
    
    cam.end();
    
    ofDisableDepthTest();
//    gui.draw();
    ofEnableDepthTest();
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

