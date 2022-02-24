pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                git 'https://github.com/linksgo2011/modern-cpp-server-boilerplate'

                sh "./build.sh"
            }
        }
    }
}
