pipeline {
    agent {label 'docker-slave2'}

    stages {
        stage('Hello') {
            steps {
                git 'https://github.com/linksgo2011/modern-cpp-server-boilerplate'

                sh 'ci.sh check'
            }
        }
    }
}