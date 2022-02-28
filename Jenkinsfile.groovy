pipeline {
    agent {label 'docker-slave2'}

    stages {
        stage('Hello') {
            steps {
                sh 'ls'
                sh './ci.sh check'
            }
        }
    }
}