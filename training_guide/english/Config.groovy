
// Path where the docToolchain will produce the output files.
// This path is appended to the docDir property specified in gradle.properties
// or in the command line, and therefore must be relative to it.
outputPath = 'build'

inputPath = '.'

inputFiles = [
        [file: 'embedded-guide-en.adoc', formats: ['html','pdf','docbook']]
             ]

taskInputsDirs = ["${inputPath}/src",
                  "${inputPath}/images",
                 ]

taskInputsFiles = ["${inputPath}/embedded-guide-en.adoc"]

confluence = [:]
confluence.with {
    input = [[ file: "build/" ]]
    api = '<your API>'
    spaceKey = 'arc42'
    createSubpages = false
    pagePrefix = ''
    pageSuffix = ''
    credentials = "${System.getenv('USER')}:${System.getenv('PASSWORD')}".bytes.encodeBase64().toString()
    extraPageContent = '<ac:structured-macro ac:name="warning"><ac:parameter ac:name="title" /><ac:rich-text-body>This is a generated page, do not edit!</ac:rich-text-body></ac:structured-macro>'
}
