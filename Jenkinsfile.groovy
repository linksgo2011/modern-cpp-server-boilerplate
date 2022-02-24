pipeline {
    agent any

    stages {
        stage('Build') {
            steps {
                sh "./build.sh"
                def scannerHome = tool 'SonarScanner 4.0';
                withSonarQubeEnv('My SonarQube Server') { // If you have configured more than one global server connection, you can specify its name
                  sh "${scannerHome}/bin/sonar-scanner -Dsonar.login=57e10da238ad6c9308ec444eacd03ba8c25ca735"
                }
            }
        }
    }
}
