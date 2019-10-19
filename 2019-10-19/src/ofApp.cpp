#include "ofApp.h"

int verticesCount = 500;
float radius = 200;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetColor(255);
    for (int i=0; i<verticesCount; i++) {
        float z = ofRandom(-1,1);
        float phi = ofDegToRad(ofRandom(360));
        float x = sqrt(1 - z * z) * cos(phi);
        float y = sqrt(1 - z * z) * sin(phi);
        vboMesh.addVertex(radius * ofVec3f(x, y, z));
        points.push_back(ofVec3f(x,y,z));
    }
    ratio = 0;
    startIndex = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    if (startIndex >= verticesCount) {
        startIndex = 0;
    }
    ratio += 0.005;
    circlePos = interpolateByRatio(ratio, startIndex);
    camera.lookAt(ofVec3f(0,0,0));
    camera.setPosition(circlePos*radius);
    if (ratio >= 1) {
        ratio = 0;
        startIndex += 1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    camera.begin();
    glPointSize(1.0);
    vboMesh.setMode(OF_PRIMITIVE_LINE_LOOP);
    ofSetColor(255, 255, 255);
    vboMesh.draw();
    camera.end();
    ofPopMatrix();
}

//--------------------------------------------------------------

ofPoint ofApp::interpolateByRatio(float ratio, int startIndex) {
    ofPoint pos;
    int targetIndex = startIndex + 1 >= verticesCount ? 0 : startIndex + 1;
    pos = (1.0 - ratio) * points[startIndex] + ratio * points[targetIndex];
    return pos;
}

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
