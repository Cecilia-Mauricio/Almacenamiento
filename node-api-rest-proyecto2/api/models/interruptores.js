const mongoose = require('mongoose');
const Schema = mongoose.Schema;
const interruptorSchema = new Schema({
 inter: {
  type: String,
  trim: true,  
  required: true,
 },
 est: {
  type: String,
  trim: true,  
  required: true,
 }
});
module.exports = mongoose.model('Interruptor', interruptorSchema);
