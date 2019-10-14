#include "ofApp.h"

int particleCount = 40000;
float a=1.074;
float b=-3.041;
float c=1.893;
float d=0.554;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){
//    a -= 0.0001;
//    b -= 0.0001;
//    c -= 0.0001;
//    d -= 0.0001;
}

//--------------------------------------------------------------
void ofApp::draw(){
        drawParticles();
        ofTranslate(ofGetWindowWidth() - 150, ofGetWindowHeight() - 150);
        drawParticles();
}

//--------------------------------------------------------------
void ofApp::drawParticles() {
    vector<ofPoint> points(particleCount);
    ofPushMatrix();

    
    vboMesh.clear();
    
    float x = 1.5;
    float y = 1.5;
    float z = 1.5;
    for(int i=0; i<particleCount; i++){
        
        float xn= sin(a * y) + c * cos(a * x);
        float yn= sin(b * x) + d * cos(b * y);
        x = xn;
        y = yn;
        
        points[i].x = x * 400;
        points[i].y = y * 400;

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
