### Microservices

These simple microservices enable us to **focus on** learning the tools - Docker, Kubernetes, CI, CD and  build the infrastructure needed around typical microservices.

### Currency Exchange Service

If you ask it the value of 1 USD in INR, or 1 Australian Dollar in INR, the Currency Exchange Service answers 
- 1 USD is 60 INR
- 1 Australian Dollars is 50 INR. 

http://localhost:8000/currency-exchange/from/EUR/to/INR

```json
{
  "id": 10002,
  "from": "EUR",
  "to": "INR",
  "conversionMultiple": 75.00,
  "exchangeEnvironmentInfo": "37f1ad927c6e v1 27c6e"
}
```

### Currency Conversion

Currency Conversion Service is used to convert a bucket of currencies. If you want to find the value of 10 USD, Currency Conversion Service returns 600. 
- **STEP 1** : Currency Conversion Service calls the Currency Exchange Service for the value of 1 USD. It gets a response back saying 60.
- **STEP 2** : The Currency Conversion Service then multiplies 10 by 60, and returns 600 back. 

http://localhost:8100/currency-conversion/from/EUR/to/INR/quantity/10

```json
{
  "id": 10002,
  "from": "EUR",
  "to": "INR",
  "conversionMultiple": 75.00,
  "quantity": 10,
  "totalCalculatedAmount": 750.00,
  "exchangeEnvironmentInfo": "37f1ad927c6e v1 27c6e",
  "conversionEnvironmentInfo": "fb6316b5713d v1 5713d"
}
```

#### How does Currency Conversion know the location of Currency Exchange?
- You don't want to HARDCODE
- Configure an Environment Variable - `CURRENCY_EXCHANGE_SERVICE_HOST`
- --env CURRENCY_EXCHANGE_SERVICE_HOST=http://currency-exchange




# ###################################################### 
##### Running Microservices on Mac M1 or ARM processors
#### If you are using a Mac M1 ARM processor or see an error about linux/arm64 in the microservices steps, you can build images in your local machine and use them!
# ###################################################### 

###### Build Currency Exchange Image
cd ROOT_OF_YOUR_DEVOPS_FOLDER
cd projects/microservices/01-currency-exchange-microservice-basic
docker build -t in28min/currency-exchange:0.0.1-RELEASE .

###### Build Currency Conversion Image
cd ../02-currency-conversion-microservice-basic
docker build -t in28min/currency-conversion:0.0.1-RELEASE .


## #####################################################
###### Commands used in this exercise
docker-compose --help
docker-compose stop
docker-compose ps
docker-compose config
docker-compose up -d
docker system prune -a
docker container ls -a
docker-compose --version
docker-compose up
docker-compose down 
docker network ls              
docker container ls
