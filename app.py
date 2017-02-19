#!flask/bin/python
from flask import Flask, jsonify, request

app = Flask(__name__)

@app.route('/')
def index():
    return "Hello, World!"




@app.route('/upload', methods=['POST'])
def upload():
    file = open('dank.png', 'w')
    file.write(result.data)
    file.close()
    return "Recieved Something", 201

if __name__ == '__main__':
    app.run(debug=True)
