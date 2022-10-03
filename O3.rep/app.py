from flask import Flask, request, render_template

app = Flask(__name__)

from Calculator import perform_calculation

@app.route("/")
def home():
        return render_template("index.html")

@app.route("/equation", methods=["POST"])
def equation():
	equation = request.form['a']

	result = perform_calculation(equation)

	return render_template('index.html', result_text=str(result))


if __name__ == "__main__":
    app.run(Debug=True)