const mongoose = require('mongoose');
const mongoDB = 'mongodb://localhost:27017/proyecto';
mongoose.connect(mongoDB,{ useUnifiedTopology: true,useNewUrlParser: true });
mongoose.Promise = global.Promise;
module.exports = mongoose;
