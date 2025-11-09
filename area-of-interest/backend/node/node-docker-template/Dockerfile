FROM docker.io/library/node:14.18.1

# Environment variables
ENV APP_FOLDER=application
ENV USER_HOME=/home/node
ENV APP_HOME=${USER_HOME}/${APP_FOLDER}
ENV USER_NAME=node
ENV USER_GROUP=${USER_NAME}

# Switch to root user
USER root

# Copy the application files
RUN mkdir -p ${APP_HOME}
WORKDIR ${APP_HOME}
COPY . .
# Fix permissions
RUN chown -R ${USER_NAME}:${USER_GROUP} ${APP_HOME}
RUN chmod +x ./entrypoint.sh

# Switch to the execution user and run the app
USER node
ENTRYPOINT exec node .
