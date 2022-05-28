// STATUS: zavrsen
// IZVOR: KTSS-2015

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(map<string, vector<string>> graph, string begin, string end) {
    queue<string> q;
    map<string, bool> visited;
    // mapa level prati nivo bfs-a svakog nodea u grafu gdje je nivo prvog 1
    map<string, int> level;

    // ovaj for seta mapu visited na false
    for (auto pair : graph) {
        visited.emplace(pair.first, false);
    }
    
    q.push(begin);
    level[begin] = 1;
    visited[begin] = true;
    string currentPerson = begin;

    while(!q.empty()) {
        currentPerson = q.front();
        q.pop();
        
        if(currentPerson == end) {
            // level kraja, tj. koliko nodeova je udaljen od root nodea
            return level[currentPerson];
        }

        for (int i = 0; i < graph[currentPerson].size(); i++) {
            if(!visited[graph[currentPerson][i]]) {
                visited[graph[currentPerson][i]] = true;
                q.push(graph[currentPerson][i]);
                // level djece trenutnog nodea je za 1 veci od trenutnog nodea
                level[graph[currentPerson][i]] = level[currentPerson] + 1;
            }
        }
    }
    return 7;
}

void isHypothesesTrue(map<string, vector<string>> graph, vector<pair<string, string>> wantedConnections) {
    // jednostavno
    for (int i = 0; i < wantedConnections.size(); i++) {
        if(bfs(graph, wantedConnections[i].first, wantedConnections[i].second) <= 6) {
            // ako je source od kraja bio udaljen manje jednako 6
            cout << "Hypotheses fulfilled\n";
        } else {
            // ako ne
            cout << "Hypotheses not fulfilled\n";
        }
    }    
}

map<string, vector<string>> makeGraph(vector<pair<string, string>> peopleConnections) {
    map<string, vector<string>> graph;
    vector<string> neighbours;

    for (int i = 0; i < peopleConnections.size(); i++) {

        // malo glup nacin, ali sam uzeo prvu osobu iz svakog para pa provjerio komsije i povezao, 
        // pa sam uzo drugu osobu iz parova i uradio isto
        string currentPerson = peopleConnections[i].first;

        for (int j = 0; j < peopleConnections.size(); j++) {
            pair<string, string> currentConnection = peopleConnections[j];
            if(currentConnection.first == currentPerson) {
                neighbours.push_back(currentConnection.second);
            } else if(currentConnection.second == currentPerson) {
                neighbours.push_back(currentConnection.first);
            }
        }

        graph.emplace(currentPerson, neighbours);
        neighbours.clear();
        
        currentPerson = peopleConnections[i].second;
        for (int j = 0; j < peopleConnections.size(); j++) {
            pair<string, string> currentConnection = peopleConnections[j];
            if(currentConnection.first == currentPerson) {
                neighbours.push_back(currentConnection.second);
            } else if(currentConnection.second == currentPerson) {
                neighbours.push_back(currentConnection.first);
            }
        }
        graph.emplace(currentPerson, neighbours);
        neighbours.clear();
    }
    return graph;
}

int main() {
    // people connections, veze osoba koje su nam date
    vector<pair<string, string>> peopleConnections;
    // wanted connections, veze osoba koje su trazene
    vector<pair<string, string>> wantedConnections;
    string name, surname;
    int numOfConnections;

    fstream file;
    
    // upisite svoj path :D
    file.open("C:\\Users\\Zakir\\Desktop\\cpp stvari\\zadaci\\prijatelji.txt", ios::in);

    if(!file.is_open()) {
        cout << "File error, could not open";
        return 0;
    }

    file >> numOfConnections;
    for (int i = 0; i < numOfConnections; i++) {
        pair<string, string> connection;

        // unese se ime i prezime, pa se spoje u string odvojene prazninom i dodate u vektor
        file >> name >> surname;
        connection.first = name + " " + surname;
        file >> name >> surname;
        connection.second = name + " " + surname;

        peopleConnections.push_back(connection);
    }

    file >> numOfConnections;
    for (int i = 0; i < numOfConnections; i++) {
        pair<string, string> connection;
        
        // isto ko na liniji 110
        file >> name >> surname;
        connection.first = name + " " + surname;
        file >> name >> surname;
        connection.second = name + " " + surname;

        wantedConnections.push_back(connection);
    }

    file.close();

    // napravimo graf
    map<string, vector<string>> graph = makeGraph(peopleConnections);

    // testiramo hipotezu za graf i trazene veze
    isHypothesesTrue(graph, wantedConnections);

    return 0;
}