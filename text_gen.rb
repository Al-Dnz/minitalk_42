require 'faker'
n = ARGV[0].to_i
str = ""
while (str.size < n)
	#c = ('a'..'z').to_a[rand(26)]
	c =  Faker::Books::Dune.quote || ('a'..'z').to_a[rand(26)]
	str <<  c
end
str = str[0..n - 1]
p str