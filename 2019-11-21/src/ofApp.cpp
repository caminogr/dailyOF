#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	camera.setDistance(400);
	ofSetCircleResolution(6);

	fbo.allocate(ofGetWidth(), ofGetHeight());

	glitch.setup(&fbo);
    glitch.setFx(OFXPOSTGLITCH_CONVERGENCE    , true);
}

//--------------------------------------------------------------
void ofApp::update(){
	fbo.begin();
	ofClear(0, 0, 0,255);
    camera.begin();
    for (int i = 0;i < 100;i++){
        if		(i % 8 == 0)ofSetColor(10);
        else if (i % 5 == 0)ofSetColor(50);
        else				ofSetColor(255, 255, 255);

        ofPushMatrix();
        ofRotateDeg(ofGetFrameNum(), 1.0, 1.0, 1.0);
        ofDrawCircle(0, 0, ofRandom(100));
        ofPopMatrix();
    }
		
    camera.end();
	fbo.end();

}

//--------------------------------------------------------------
void ofApp::draw(){
	glitch.generateFx();
    
	ofSetColor(255);
	fbo.draw(0, 0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){}

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

