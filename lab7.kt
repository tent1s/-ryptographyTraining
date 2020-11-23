import kotlin.math.log2

class Main {
        val text = ("Я был разбужен спозаранку Щелчком оконного стекла. Размокшей каменной баранкой В воде Венеция плыла. Все было тихо, и, однако, Во сне я слышал крик, и он Подобьем смолкнувшего знака Еще тревожил небосклон.").toLowerCase()
        private val alphabet = arrayOf("а", "б", "в", "г", "д", "е", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я ")
        val newText = text.replace(" ", "").replace(",", "").replace(".", "")

        //1
        private fun counter(symbol: String): Int {
            var count = 0;
            for (i in text) {
                if (i.toString() == symbol) count += 1
            }
            return count
        }
        fun k1(): Double {
            var result = 0.0
            for (i in alphabet.indices) {
                var count = counter(alphabet[i])
                if (count>0) {
                    val px: Double = count.toDouble()/split(1)
                    result += px * log2((1/px))
                }
            }
            return result
        }
        //2
        private fun counter(symbol1: String, symbol2: String): Int {
            var count = 0
            for (i in 0 until newText.length - 1) {
                if (newText[i].toString()+newText[i+1] == symbol1 + symbol2) count++
            }
            return count
        }
        fun k2(): Double {
            var result = 0.0
            for (i in alphabet.indices) {
                for (j in alphabet.indices) {
                    val count = counter(alphabet[i], alphabet[j])
                    if (count > 0) {
                        val px: Double = count.toDouble()/split(2)
                        result += px * log2((1/px))
                    }
                }
            }
            return result
        }


        //3
        private fun counter(symbol1: String, symbol2: String, symbol3: String): Int {
            var count = 0
            for (i in 0 until newText.length - 2) {
                if (newText[i].toString()+newText[i+1]+newText[i+2] == symbol1 + symbol2 + symbol3) count++
            }
            return count
        }

        fun k3(): Double {
            var result = 0.0
            for (i in alphabet.indices) {
                for (j in alphabet.indices) {
                    for (x in alphabet.indices) {
                        val count = counter(alphabet[i], alphabet[j], alphabet[x])
                        if (count > 0) {
                            val px: Double = count.toDouble()/split(3)
                            result += px * log2((1/px))
                        }
                    }
                }
            }
            return result
        }



        //4
        private fun counter(symbol1: String, symbol2: String, symbol3: String, symbol4: String): Int {
            var count = 0
            for (i in 0 until newText.length - 3) {
                if (newText[i].toString()+newText[i+1]+newText[i+2]+newText[i+3] == symbol1 + symbol2 + symbol3 + symbol4) count++
            }
            return count
        }
        fun k4(): Double {
            var result = 0.0
            for (i in alphabet.indices) {
                for (j in alphabet.indices) {
                    for (x in alphabet.indices) {
                        for (y in alphabet.indices) {
                            val count = counter(alphabet[i], alphabet[j], alphabet[x], alphabet[y])
                            if (count > 0) {
                                val px: Double = count.toDouble()/split(4)
                                result += px * log2((1/px))
                            }
                        }
                    }
                }
            }
            return result
        }


        //5
        private fun counter(symbol1: String, symbol2: String, symbol3: String, symbol4: String, symbol5: String): Int {
                var count = 0
                for (i in 0 until newText.length - 4) {
                    if (newText[i].toString()+newText[i+1]+newText[i+2]+newText[i+3]+newText[i+4] == symbol1 + symbol2 + symbol3 + symbol4 + symbol5) count++
                }
                return count
        }

        fun k5(): Double {
            var result = 0.0
            for (i in alphabet.indices) {
                for (j in alphabet.indices) {
                    for (x in alphabet.indices) {
                        for (y in alphabet.indices) {
                            for (n in alphabet.indices) {
                                val count = counter(alphabet[i], alphabet[j], alphabet[x], alphabet[y], alphabet[n])
                                if (count > 0) {
                                    val px: Double = count.toDouble()/split(5)
                                    result += px * log2((1/px))
                                }
                            }
                        }
                    }
                }
            }
            return result
        }

        private fun split(k: Int): Int {
            return newText.length - k + 1
        }

}

fun main() {
    println(Main().text)
    println(Main().newText)
    println(Main().k1()/1)
    println(Main().k2()/2)
    println(Main().k3()/3)
    println(Main().k4()/4)
    println(Main().k5()/5)
}