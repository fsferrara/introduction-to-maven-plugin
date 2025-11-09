FROM node:14 as base

WORKDIR /app

COPY package.json .
COPY package-lock.json .

RUN npm set progress=false && npm set depth 0
RUN npm ci --only=production
RUN cp -R node_modules prod_node_modules

FROM base

COPY --from=base /app/prod_node_modules ./node_modules
COPY . .

CMD ["node", "src/index.js"]
