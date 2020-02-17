#include "ofApp.h"

int iterateCount = 100;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    gui.setup();
    gui.add(X.setup("X", 1, 1, 3000));
    gui.add(Y.setup("Y", 1, 1, 3000));
    gui.add(Z.setup("Z", 1, 1, 3000));
    gui.add(Deg.setup("Deg", 1, 1, 3000));

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    ofSetColor(255);

    vboMesh.clear();
    
    for (int i=0; i<1000; i++) {
//        float xn= sin(a * y) + c * cos(a * x);
//        float yn= sin(b * x) + d * cos(b * y);
//        x = xn;
//        y = yn;

        vboMesh.addVertex(ofVec3f(i, i, 0));
        vboMesh.addVertex(ofVec3f(0, 0,  Z * i/2));
        vboMesh.addVertex(ofVec3f(X * i, Y * i, Z * i));
    }
    
    ofPushMatrix();
    ofRotateDeg(500, 10, 10, 10);
//    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    glPointSize(1.0);
    vboMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    vboMesh.draw();
    ofPopMatrix();
    
    gui.draw();
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
