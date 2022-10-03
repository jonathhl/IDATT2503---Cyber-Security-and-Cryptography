FROM python:alpine

WORKDIR /app

EXPOSE 5000:5000
ENV Flask.app=app.py
COPY ./app.py /app
COPY ./Calculator.py /app
COPY ./flag.zip /app
COPY ./requirements.txt /app
COPY ./templates/index.html /templates
#COPY . /app
RUN pip install -r requirements.txt

ENTRYPOINT [ "flask" ]
CMD [ "run", "--host", "0.0.0.0" ]