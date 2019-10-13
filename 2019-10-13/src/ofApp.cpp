#include "ofApp.h"

int particleCount = 10000;
float a=0.474;
float b=-3.741;
float c=2.293;
float d=0.954;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    a += ofRandom(-0.3,0.3);
    b += ofRandom(-0.3,0.3);
    c += ofRandom(-0.3,0.3);
    d += ofRandom(-0.3,0.3);
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<4; i++){
        ofPushMatrix();
        ofTranslate((ofGetWindowWidth()/2 - 150) * i, 0);
        drawParticles();
        ofTranslate(0,ofGetWindowHeight()/2 - 150);
        drawParticles();
        ofTranslate(0,ofGetWindowHeight()/2 - 150);
        drawParticles();
        ofPopMatrix();
    }
    
}

void ofApp::drawParticles() {
    vector<ofPoint> points(particleCount);
    ofPushMatrix();

    
    vboMesh.clear();
    
    float x = 1.0;
    float y = 1.0;
    float z = 1.0;
    for(int i=0; i<particleCount; i++){
        
        float xn= ofNoise(sin(a * y) + c * cos(a * x));
        float yn= ofNoise(sin(b * x) + d * cos(b * y));
        x = xn;
        y = yn;
        
        points[i].x = x * 300;
        points[i].y = y * 300;

        vboMesh.addVertex(ofVec3f(points[i].x, points[i].y, 0.0));
        vboMesh.addColor(255);
    }
    
    glPointSize(1.0);
    vboMesh.setMode(OF_PRIMITIVE_POINTS);
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
