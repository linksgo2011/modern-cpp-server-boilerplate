pipeline {
    agent {label 'docker-slave2'}

    stages {
        stage('Static check') {
            steps {
                sh 'ls'
                sh './ci.sh check'
            }
        }

        stage('Build') {
            steps {
                sh 'ls'
                sh './ci.sh build'
            }
        }

        stage('Unit Testing') {
            steps {
                sh 'ls'
                sh './ci.sh unitTest'
            }
        }
    }
}