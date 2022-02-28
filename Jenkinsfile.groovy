pipeline {
    agent {label 'docker-slave2'}

    stages {
        stage('Hello') {
            steps {
                sh 'ci.sh check'
            }
        }
    }
}