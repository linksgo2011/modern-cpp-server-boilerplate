pipeline {
    agent {label 'docker-slave2'}

    stages {
        stage('Static Check') {
            steps {
                sh "./ci.sh check"
            }
        }
    }
}
